import { day01_part1, day01_part2 } from './day01';

type Solution = () => Promise<number>;

async function print_solution(day: number, part1: Solution, part2?: Solution) {
  return {
    day,
    part1: await part1(),
    part2: await part2?.(),
  };
}

async function main() {
  console.time('execution')
  const solutions = await Promise.all([
    print_solution(1, day01_part1, day01_part2),
  ]);

  const solutionByDay = solutions.reduce<
    Record<number, { part1: number; part2?: number }>
  >((acc, { day, ...parts }) => {
    acc[day] = parts;
    return acc;
  }, {});

  console.table(solutionByDay);
  console.timeEnd('execution')
}

main();
