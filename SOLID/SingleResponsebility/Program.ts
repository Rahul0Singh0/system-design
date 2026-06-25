abstract class FileManagerAndParser {
    abstract read(buffer: Uint8Array, size: number): number;

    abstract write(buffer: Uint8Array, size: number): void;

    abstract parse(data: string): number[];
}

abstract class FileManager {
    abstract read(buffer: Uint8Array, size: number): number;

    abstract write(buffer: Uint8Array, size: number): void;
}

abstract class Parser {
    abstract parse(data: string): number[];
}