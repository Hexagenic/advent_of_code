use crate::error::Error;

mod day1;
mod day2;

pub type PuzzleSolution = Option<fn() -> Result<i64, Error>>;

#[must_use]
pub fn get_solution(day: u8) -> (PuzzleSolution, PuzzleSolution) {
    match day {
        1 => (Some(day1::part_a), Some(day1::part_b)),
        2 => (Some(day2::part_a), Some(day2::part_b)),
        _ => (None, None),
    }
}

#[allow(unused)]
pub const MAX_SOLVED_DAY: u8 = 2;
