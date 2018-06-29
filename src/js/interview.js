'use strict';

// Create a function batches that returns the maximum number of whole batches
// that can be cooked from a recipe.
(() => {
    const batches = function (recipe, available) {
        let keys = Object.keys(recipe);
        console.log(keys);
        let maps = keys.map(k => available[k] / recipe[k] || 0);
        console.log(maps);
        let min = Math.min(...maps);
        console.log(min);
        let result = Math.floor(min);
        console.log(result);
    };

    // 0 batches can be made
    batches({
        milk: 100,
        butter: 50,
        flour: 5
    }, {
        milk: 132,
        butter: 48,
        flour: 51
    })
    batches({
        milk: 100,
        flour: 4,
        sugar: 10,
        butter: 5
    }, {
        milk: 1288,
        flour: 9,
        sugar: 95
    })

    // 1 batch can be made
    batches({
        milk: 100,
        butter: 50,
        cheese: 10
    }, {
        milk: 198,
        butter: 52,
        cheese: 10
    })

    // 2 batches can be made
    batches({
        milk: 2,
        sugar: 40,
        butter: 20
    }, {
        milk: 5,
        sugar: 120,
        butter: 500
    })
})();