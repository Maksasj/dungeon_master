import path from "path";
import fs from "fs";
import { argv } from "zx";
import { description, version } from "../package.json";

export const processArguments = () => {
    const useHelpOption = "Type image-converter --help to see all available options.";

    if (argv.help || argv.h) {
        console.log(`${description}
Usage: image-converter [options] path

Options:
    -o, --output       set output directory
    -v, --version      output the version number
    -h, --help         display help
`);
        process.exit(0);
    }

    if (argv.v || argv.version) {
        console.log(`image-converter version ${version}`);
        process.exit(0);
    }

    if (argv._.length <= 1) {
        console.error(`No path specified. ${useHelpOption}`);
        process.exit(1);
    }

    if (!argv.o && !argv.output) {
        console.error(`No output specified. ${useHelpOption}`);
        process.exit(1);
    }

    const inputPath = argv._[1];
    const outputPath = argv.o || argv.output;

    if (!fs.statSync(outputPath).isDirectory()) {
        console.error("Output path must be a directory.");
        process.exit(1);
    }

    if (!fs.statSync(inputPath).isDirectory()) {
        console.error("Input path must be a directory.");
        process.exit(1);
    }

    return {
        inputPath,
        outputPath,
    };
};
