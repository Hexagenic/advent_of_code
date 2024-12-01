import fs from "fs";
import readline from 'readline';

export async function day01_part1(): Promise<number> {
    const input = fs.createReadStream('input/day01.txt');
    const rl = readline.createInterface({ input });

    const ls: number[] = [];
    const rs: number[] = [];

    for await (const line of rl) {
        const [l, r] = line.split('   ');
        ls.push(parseInt(l));
        rs.push(parseInt(r))
    }

    ls.sort((a, b) => a - b);
    rs.sort((a, b) => a - b);

    let sum = 0;
    for (let i = 0; i < ls.length; i++) {
        sum += Math.abs(ls[i] - rs[i]);
    }

    return sum;
}

export async function day01_part2(): Promise<number> {
    const input = fs.createReadStream('input/day01.txt');
    const rl = readline.createInterface({ input });

    const ls: number[] = [];
    const rs: number[] = [];

    for await (const line of rl) {
        const [l, r] = line.split('   ');
        ls.push(parseInt(l));
        rs.push(parseInt(r))
    }

    const lSet = new Set(ls);

    let sum = 0;

    for (const l of lSet.values()) {
        const count = rs.filter(r => r === l).length;
        sum += count * l;
    }

    return sum;
}