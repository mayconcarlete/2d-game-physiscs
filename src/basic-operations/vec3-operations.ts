import { Operations } from "./interface-operations";

export type Vector3 = {
  x: number,
  y: number,
  z: number
}


export class Vec3 implements Operations<Vector3>{
  x: number;
  y: number;
  z: number;
  constructor(x: number, y: number, z: number){
    this.x = x;
    this.y = y;
    this.z = z;
  }
  sum(v: Vector3): void {
    this.x += v.x;
    this.y += v.y;
    this.z += v.z;
  }
  static sum(a: Vector3, b: Vector3):Vector3{
    const result = new Vec3(0, 0, 0);
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result
  }
  sub(v: Vector3): void {
    this.x -= v.x;
    this.y -= v.y;
    this.z -= v.z;
  }
  static sub(a: Vector3, b: Vector3): Vector3{
    const result = new Vec3(0, 0, 0);
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
  }
  dot(v: Vector3): number {
    return (this.x * v.x + this.y * v.y + this.z * v.z);
  }
  scale(value: number): void {
    this.x *= value;
    this.y *= value;
    this.z *= value;
  }
  magnitude(): number {
    return Math.sqrt((this.x * this.x) + (this.y * this.y) + (this.z * this.z));
  }
  normalize(): void {
    const magnitude = this.magnitude();
    this.x /= magnitude;
    this.y /= magnitude;
    this.z /= magnitude;
  }
  cross(v: Vector3): Vec3 | undefined {
    const dot = new Vec3(0, 0, 0,);
    dot.x = this.y * v.z - this.z * v.y;
    dot.y = this.z * v.x - this.x * v.z;
    dot.z = this.x * v.y - this.y * v.x;
    return dot;
  }
  printVector(): void {
    console.log(`X: ${this.x} - Y: ${this.y} - Z: ${this.z}`);
  }
  static printVector(v: Vector3): void{
    console.log(`X: ${v.x} - Y: ${v.y} - Z: ${v.z}`);
  }
}