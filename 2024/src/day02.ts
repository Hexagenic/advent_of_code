import fs from 'fs';

function getUnsafety(line: number[]): number {
  let dir: 'l' | 'r' | null = null;
  let previous: number | null = null;

  let errorCount = 0;

  for (let num of line) {
    if (previous == null) {
      previous = num;
      continue;
    }

    const diff = Math.abs(num - previous);
    let hasError = false;

    if (diff < 1 || diff > 3) {
      hasError = true;
    }

    const localDir = previous < num ? 'r' : 'l';

    if (dir == null) {
      dir = localDir;
    } else if (dir != localDir) {
      hasError = true;
    }
    
    if (hasError) {
      errorCount++;
    }

    previous = num;
  }

  return errorCount;
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

    let errors = getUnsafety(nums);

    if (errors === 0) {
      safeLines++;
    }

    if (errors <= 1) {
      safeLinesWithDampening++;
    }
  }

  return [safeLines, safeLinesWithDampening];
}
