import { accessSync, mkdirSync, writeFileSync } from "fs";
import { dirname } from "path";

export const safeWriteFileSync = (path: string, content: string) => {
    const dir = dirname(path);
    try {
        accessSync(dir);
    } catch {
        mkdirSync(dirname(path), { recursive: true });
    }

    writeFileSync(path, content);
};
