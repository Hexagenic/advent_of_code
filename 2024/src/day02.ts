import fs from 'fs';

function isSafe(line: number[]): boolean {
  let dir: 'l' | 'r' | null = null;
  let previous: number | null = null;

  for (let num of line) {
    if (previous == null) {
      previous = num;
      continue;
    }

    const diff = Math.abs(num - previous);

    if (diff < 1 || diff > 3) {
      return false;
    }

    const localDir = previous < num ? 'r' : 'l';

    if (dir == null) {
      dir = localDir;
    } else if (dir != localDir) {
      return false;
    }

    previous = num;
  }

  return true;
}

function isSafeDampened(line: number[]): boolean {
  for (let i = 0; i < line.length; i++) {
    const dampenedLine = line.slice();
    dampenedLine.splice(i, 1);

    if (isSafe(dampenedLine)) {
      return true;
    }
  }
  return false;
}

export default function day02() {
  const input = fs.readFileSync('input/day02.txt', 'ascii');
  const lines = input.split('\n');

  let safeLines = 0;
  let safeLinesWithDampening = 0;

  for (let line of lines) {
    if (line.length == 0) {
      continue;
    }

    const nums = line.split(' ').map((v) => parseInt(v));

    if (isSafe(nums)) {
      safeLines++;
    }

    if (isSafeDampened(nums)) {
      safeLinesWithDampening++;
    }
  }

  return [safeLines, safeLinesWithDampening];
}
