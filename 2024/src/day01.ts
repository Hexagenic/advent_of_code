import fs from 'fs';

export default function day01(): [number, number] {
  const input = fs.readFileSync('input/day01.txt', 'ascii');
  const lines = input.split('\n');
  const ls: number[] = [];
  const rs: number[] = [];

  let part1 = 0;

  for (const line of lines) {
    if (!line.length) continue;
    const [l, r] = line.split('   ').map((v) => parseInt(v));
    ls.push(l);
    rs.push(r);
    part1 += Math.abs(l - r);
  }

  let part2 = 0;

  for (const l of ls) {
    const count = rs.filter((r) => r === l).length;
    part2 += count * l;
  }

  return [part1, part2];
}
