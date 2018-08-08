"use strict";

// Create a function batches that returns the maximum number of whole batches
// that can be cooked from a recipe.
(() => {
  const batches = function(recipe, available) {
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
  batches(
    {
      milk: 100,
      butter: 50,
      flour: 5
    },
    {
      milk: 132,
      butter: 48,
      flour: 51
    }
  );
  batches(
    {
      milk: 100,
      flour: 4,
      sugar: 10,
      butter: 5
    },
    {
      milk: 1288,
      flour: 9,
      sugar: 95
    }
  );

  // 1 batch can be made
  batches(
    {
      milk: 100,
      butter: 50,
      cheese: 10
    },
    {
      milk: 198,
      butter: 52,
      cheese: 10
    }
  );

  // 2 batches can be made
  batches(
    {
      milk: 2,
      sugar: 40,
      butter: 20
    },
    {
      milk: 5,
      sugar: 120,
      butter: 500
    }
  );
})();

// How do you clone an object in JavaScript?
(() => {
  const obj = {
    a: 1,
    b: 2,
    f: () => {
      conosle.log(`function obj`);
    },
    n: {
      c: 3,
      d: 4
    }
  };

  // Using the object spread operator ..., the object's own enumerable properties
  // can be copied into the new object. With this technique, prototypes are
  // ignored. In addition, nested objects are not cloned, but rather their
  // references get copied, so nested objects still refer to the same objects as
  // the original.
  const shallowClone = {
    ...obj
  };
  console.log(shallowClone);

  // deep-clone a simple object, but it is CPU-intensive and only accepts valid
  // JSON (therefore it strips functions and does not allow circular references).
  const deepClone = JSON.parse(JSON.stringify(obj));
  console.log(deepClone);

  const deepAssignClone = Object.assign({}, obj);
  console.log(deepAssignClone);

  // another more verbose alternative that shows the concept in greater depth.
  const deepReduceClone = Object.keys(obj).reduce(
    (acc, key) => ((acc[key] = obj[key]), acc),
    {}
  );
  console.log(deepReduceClone);
})();

(() => {
  Symbol("foo") !== Symbol("foo");
  const foo = Symbol();
  const bar = Symbol();
  typeof foo === "symbol";
  typeof bar === "symbol";

  console.log(Symbol.for("foo"));
  console.log(Symbol.keyFor(Symbol.for("foo")));

  let obj = {};
  obj[foo] = "foo";
  obj[bar] = "bar";
  console.log(obj[foo]);
  console.log(obj[bar]);

  console.log(JSON.stringify(obj)); // {}
  console.log(Object.keys(obj)); // []
  console.log(Object.getOwnPropertyNames(obj)); // []
  console.log(Object.getOwnPropertySymbols(obj)); // [ Symbol(), Symbol() ]
})();

(() => {
  console.log(`null === null: ${null === null}`);

  const equals = (a, b) => {
    if (a === b) return true;
    if (a instanceof Date && b instanceof Date)
      return a.getTime() === b.getTime();
    if (!a || !b || (typeof a !== "object" && typeof b !== "object"))
      return a === b;
    if (a === null || a === undefined || b === null || b === undefined)
      return false;
    if (a.prototype !== b.prototype) return false;
    let keys = Object.keys(a);
    if (keys.length !== Object.keys(b).length) return false;
    return keys.every(k => equals(a[k], b[k]));
  };

  console.log(
    `equals({ a: [2, { e: 3 }], b: [4], c: 'foo' }, { a: [2, { e: 3 }], b: [4], c: 'foo' }): ${equals(
      { a: [2, { e: 3 }], b: [4], c: "foo" },
      { a: [2, { e: 3 }], b: [4], c: "foo" }
    )}`
  );
})();

(() => {
  console.log(
    `Generate an array, containing the Fibonacci sequence, up until the nth term.`
  );

  console.log([...Array(3)]);
  console.log(...Array(3));
  console.log(Array(3));

  const fibonacci = n =>
    [...Array(n)].reduce(
      (acc, val, i) => acc.concat(i > 1 ? acc[i - 1] + acc[i - 2] : i),
      []
    );

  console.log(`fibonacci(10): ${fibonacci(10)}`);
})();

(() => {
  console.log(`What will the console log in this example?`);
  var foo = 1;
  var foobar = function() {
    console.log(foo);
    var foo = 2;
  };
  foobar();
})();

(() => {
  console.log(`What does the following function return?`);
  function greet() {
    return
    {
      message: "hello"
    }
  }
  console.log(`greet() ${greet()}`);
})();

(() => {
  console.log(`What is the difference between a parameter and an argument?`);
  function myFunction(parameter1, parameter2) {
    console.log(arguments[0]) // "argument1"
  }
  myFunction("argument1", "argument2")
  console.log(`myFunction.length => ${myFunction.length}`);
})();

(() => {
  console.log(`Create a standalone function bind that is functionally equivalent to the method Function.prototype.bind`);
  const bind = (fn, context) => (...args) => fn.apply(context, args)
  function example() {
    console.log(this)
  }
  const boundExample = bind(example, { a: true })
  boundExample.call({ b: true }) // logs { a: true }
})();
