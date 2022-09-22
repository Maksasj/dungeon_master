export const rgbToHex = (red: number, green: number, blue: number) => {
    const r = Math.trunc((red / 255) * 31);
    const g = Math.trunc((green / 255) * 31);
    const b = Math.trunc((blue / 255) * 31);

    return r + (g << 5) + (b << 10);
};
