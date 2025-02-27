const lenLongestFibSubseq = (arr) => {
    const set = new Set(arr);
    let maxLength = 0;
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            for (let a = arr[i], b = arr[j], len = 3; set.has(a + b); len++) {
                [a, b] = [b, a + b];
                maxLength = Math.max(maxLength, len);
            }
        }
    }
    return maxLength;
};
