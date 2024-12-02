import day01 from './day01';
import day02 from './day02';

type Solution = () => number[];

function print_solution(day: number, solution: Solution) {
  const start = process.hrtime.bigint();
  const result = solution();
  const end = process.hrtime.bigint();
  const timeBig = end - start;
  const time = parseInt(timeBig.toString()) / 1000000;

  console.log(`day ${day.toString().padStart(2, ' ')}`, result, '-', `${time.toFixed(5)} ms`);
}

console.time('execution');

print_solution(1, day01);
print_solution(2, day02);

console.log();
console.timeEnd('execution');
