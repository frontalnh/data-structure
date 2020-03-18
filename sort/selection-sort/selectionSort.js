function selectionSort(arr) {
  const result = [];
  while (arr.length) {
    let largestIndex = findLargestIndex(arr);
    result.push(arr[largestIndex]);
    arr.splice(largestIndex, 1);
  }

  return result;
}

function findLargestIndex(arr) {
  let largestValue = 0;
  let largestIndex = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] > largestValue) {
      largestValue = arr[i];
      largestIndex = i;
    }
  }
  console.log(largestIndex);

  return largestIndex;
}

const arr = [1, 4, 2, 7, 4, 3, 7];
console.log(selectionSort(arr, 0));
