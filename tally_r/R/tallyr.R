#' @useDynLib tallyR tally_
#' @export
tally <- function(x) .Call(tally_, x)
