import {Vec2, Vector2} from "./basic-operations"

//////////////////////////
// sum vector2
// sum B in vector A
//////////////////////////
const a = new Vec2(0, 0);
const b = new Vec2(2, 2);
a.sum(b)
a.printVector()

//////////////////////////
// sum 2 vectors type vector2
//////////////////////////
const c = new Vec2(2, 2);
const d = new Vec2(2, 2);
const resultSum = Vec2.sum(c, d)
Vec2.printVector(resultSum)

//////////////////////////
// sub vector2
// sub B in vector A
//////////////////////////
const e = new Vec2(2, 2);
const f = new Vec2(2, 2);
e.sub(f);
e.printVector()

//////////////////////////
// sub 2 vectors type vector2
//////////////////////////

const g = new Vec2(2, 2);
const h = new Vec2(2, 2);
const resultSub = Vec2.sub(g, h);
Vec2.printVector(resultSub)

//////////////////////////
// Dot vectors type vector2
//////////////////////////

const i = new Vec2(-6, 8);
const j = new Vec2(5, 12);
const resultDot = i.dot(j);
console.log(resultDot)
