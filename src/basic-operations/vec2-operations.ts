import {Operations} from "./interface-operations"

export type Vector2 = {
  x: number,
  y: number
}

export class Vec2 implements Operations<Vector2>{
  x: number
  y: number
  constructor( x: number,y: number){
    this.x = x;
    this.y = y;
  }
  sum(v: Vector2): void {
    this.x += v.x;
    this.y += v.y;
  }
  static sum(a:Vector2, b: Vector2):Vector2{
    const result = new Vec2(0, 0);
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
  }
  sub(v: Vector2): void {
    this.x -= v.x;
    this.y -= v.y;
  }
  static sub(a:Vector2, b: Vector2): Vector2{
    const result = new Vec2(0, 0);
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result
  }
  dot(v: Vector2): number {
    return (this.x * v.x + this.y * v.y);
  }
  scale(value: number): void {
    this.x *= value;
    this.y *= value;
  }
  magnitude(): number {
    return Math.sqrt((this.x * this.x) + (this.y * this.y));
  }
  normalize(): void {
    const magnitude = this.magnitude();
    this.x /= magnitude;
    this.y /= magnitude;
  }
  cross(v: Vector2): Vector2 | undefined{
    console.log("not cross vector with length 2.");
    return undefined
  }
  printVector(): void{
    console.log(`X: ${this.x} - Y: ${this.y}`);
  }
  static printVector(v: Vector2): void{
    console.log(`X: ${v.x} - Y: ${v.y}`);
  }
}