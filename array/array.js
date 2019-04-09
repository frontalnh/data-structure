let arr1 = [1, 2, 3, 4, 5];
let arr2 = [1, 2, 3, 4, 5];
let arr3 = [1, 2, 3, 4, 5];

console.time('delete first element');
arr1.shift();
console.timeEnd('delete first element');
console.time('delete second element');
arr2.splice(1, 1);
console.timeEnd('delete second element');
console.time('delete last element');
arr3.pop();
console.timeEnd('delete last element');
