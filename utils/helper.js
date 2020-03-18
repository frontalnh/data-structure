module.exports = {
  genArray: function(length, decimal) {
    const result = [];
    for (let i = 0; i < length; i++) {
      result.push(Math.floor(Math.random() * Math.pow(10, decimal)));
    }

    return result;
  }
};
