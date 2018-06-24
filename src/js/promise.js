'use strict';

(() => {
    // basic usage
    console.log("Started");

    let myPromise = new Promise((resolve, reject) => {
        console.log("Promise started!");

        setTimeout(function () {
            resolve("Success!");
        }, 1000);
    });

    myPromise.then((successMessage) => {
        console.log("Promise fullfilled!");
        console.log("Yah, " + successMessage);
    }).catch(() => {
        console.log("Promise rejected!");
    });

    console.log("Promise made");
})();