export const rgbToHex = (r: number, g: number, b: number) => {
    return r + (g << 5) + (b << 10);
};
