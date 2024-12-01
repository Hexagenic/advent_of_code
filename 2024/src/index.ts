import { day01_part1, day01_part2 } from './day01';

type Solution = () => Promise<number>;

async function print_solution(
  day: number,
  solution1: Solution,
  solution2?: Solution,
) {
  const start = new Date().getTime();
  const part1 = await solution1();
  const part2 = await solution2?.();
  const end = new Date().getTime();

  const time = `${end - start} ms`;

  console.log(
    `day ${day.toString().padStart(2, ' ')}`,
    [part1, part2],
    '-',
    time,
  );
}

async function main() {
  console.time('execution');

  await print_solution(1, day01_part1, day01_part2);

  console.log();
  console.timeEnd('execution');
}

main();
