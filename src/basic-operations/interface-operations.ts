export interface Operations <T = any>{
  sum(v: T):void
  sub(v: T): void
  dotMultiplication(v: T): void
  scale(value: number): void
  magnitude(): number
  normalize(): void
  cross(v: T): T
  printVector(): void
}