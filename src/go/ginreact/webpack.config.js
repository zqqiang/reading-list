const path = require('path');

module.exports = {
    entry: './public/main.js',
    output: {
        filename: 'bundle.js',
        path: path.resolve(__dirname, 'public')
    },
    module: {
        loaders: [{
            test: /\.js(x?)$/,
            exclude: [/node_modules/],
            loader: 'babel-loader?presets[]=es2015&presets[]=react'
        }]
    },
};