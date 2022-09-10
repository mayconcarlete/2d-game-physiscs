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
const result = Vec2.sum(c, d)
Vec2.printVector(result)
