import day01 from './day01';

type Solution = () => [number, number?];

function print_solution(day: number, solution: Solution) {
  const start = new Date().getTime();
  const result = solution();
  const end = new Date().getTime();

  const time = `${end - start} ms`;

  console.log(`day ${day.toString().padStart(2, ' ')}`, result, '-', time);
}

console.time('execution');

print_solution(1, day01);

console.log();
console.timeEnd('execution');
