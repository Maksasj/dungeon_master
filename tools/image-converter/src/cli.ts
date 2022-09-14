#!/usr/bin/env zxpp

import path from "path";
import fs from "fs/promises";
import getPixels from "get-pixels";
import { argv } from "zx";
import { processArguments } from "./processArguments";

const { inputPath, outputPath } = processArguments();

const inputDir = await fs.readdir(inputPath);
const outputDir = await fs.readdir(outputPath);

const inputFiles = inputDir.map((filePath) => path.join(process.cwd(), inputPath, filePath));

console.log(inputFiles);

for (const filePath of inputFiles) {
    getPixels(filePath, (err, pixels) => {
        if (err) {
            console.error("Bad image path");
            process.exit(1);
        }
        // TODO
    });
}
