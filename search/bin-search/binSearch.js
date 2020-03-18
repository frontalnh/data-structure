const helper = require('../../utils/helper');

function binSearch(arr, item) {
  arr.sort((a, b) => a - b);
  if (arr.length === 0) return false;
  let index = Math.floor(arr.length / 2);
  if (arr[index] === item) return true;

  if (arr[index] < item) {
    return binSearch(arr.slice(index + 1), item);
  } else {
    return binSearch(arr.slice(0, index - 1), item);
  }
}

const arr = helper.genArray(10, 2);
console.log('original array: ', arr);
console.log(binSearch(arr, arr[4]));
console.log(binSearch(arr, 1000));
