const superagentPromise = require('superagent-promise');
const _superagent = require('superagent');

const superagent = superagentPromise(_superagent, global.Promise);

const API_ROOT = 'https://maps.googleapis.com/maps/api/place';

// https://maps.googleapis.com/maps/api/place/nearbysearch/json
// https://maps.googleapis.com/maps/api/place/details/json

const encode = encodeURIComponent;

const handleErrors = err => {
    if (err && err.response && err.response.status === 401) {
        console.log('err.response.status', err.response.status);
    }
    return err;
};

const responseBody = res => res.body;

const tokenPlugin = req => {};

const requests = {
    del: url =>
        superagent
        .del(`${API_ROOT}${url}`)
        .use(tokenPlugin)
        .end(handleErrors)
        .then(responseBody),
    get: url =>
        superagent
        .get(`${API_ROOT}${url}`)
        .use(tokenPlugin)
        .end(handleErrors)
        .then(responseBody),
    put: (url, body) =>
        superagent
        .put(`${API_ROOT}${url}`, body)
        .use(tokenPlugin)
        .end(handleErrors)
        .then(responseBody),
    post: (url, body) =>
        superagent
        .post(`${API_ROOT}${url}`, body)
        .use(tokenPlugin)
        .end(handleErrors)
        .then(responseBody),
};

const location = '-33.8670522,151.1957362';
const radius = 500;
const type = 'restaurant';
const key = 'AIzaSyBpESHbNIQ7LDc5P4ZlXC0D8Q6VgJuHYSc';

const details = (place_id) => {
    requests.get(`/details/json?placeid=${place_id}&key=${key}`)
        .then(({ result, status }) => {
            console.log(result.formatted_address);
        });
}

requests.get(`/nearbysearch/json?location=${location}&radius=${radius}&type=${type}&key=${key}`)
    .then(({ next_page_token, results, status }) => {
        results.map(result => {
            details(result.place_id);
        })
    });