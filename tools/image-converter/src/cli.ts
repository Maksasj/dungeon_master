#!/usr/bin/env zxpp

import path from "path";
import fs from "fs";
import rgbToHex from "rgb-hex";
import { processArguments } from "./processArguments";
import { PNG } from "pngjs";
import { safeWriteFileSync } from "./safeWriteFileSync";

const { inputPath, outputPath } = processArguments();

const inputDir = await fs.promises.readdir(inputPath);

const inputFiles = inputDir.map((filePath) => path.join(process.cwd(), inputPath, filePath));

console.log(inputFiles);

for (const filePath of inputFiles) {
    fs.createReadStream(filePath)
        .pipe(new PNG())
        .on("parsed", function () {
            const length = this.width * this.height;
            let output = `const unsigned short image[${length}] = {\n`;

            for (let y = 0; y < this.height; y++) {
                output += "\t";

                for (let x = 0; x < this.width; x++) {
                    const index = (this.width * y + x) << 2;

                    const r = this.data[index],
                        g = this.data[index + 1],
                        b = this.data[index + 2];

                    const hex = rgbToHex(r, g, b);

                    output += `0x${hex},`;
                }

                output += "\n";
            }

            output += "};";

            const fileName = path.parse(filePath).name;
            safeWriteFileSync(path.join(outputPath, `${fileName}.h`), output);
        });
}
