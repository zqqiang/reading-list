const superagentPromise = require('superagent-promise');
const _superagent = require('superagent');
const { Chromeless } = require('chromeless');
const S = require('string');

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

const location = '49.282965, -123.115443';
const radius = 3000;
const type = 'restaurant';
const key = '';

async function detailsFromUrl(url) {
    const chromeless = new Chromeless();

    const screenshot = await chromeless
        .goto(url)
        .screenshot()

    console.log(screenshot);

    await chromeless.end()
};

const category = (tags) => {
    let cate = '';
    if (tags.isSushi) cate += 'Sushi ';
    if (tags.isKorean) cate += 'Korean ';
    if (tags.isChinese) cate += 'Chinese ';
    if (tags.isFrench) cate += 'French ';
    if (tags.isIndian) cate += 'Indian ';
    if (tags.isItalian) cate += 'Italian ';
    if (tags.isMexican) cate += 'Mexican ';
    if (tags.isSeafood) cate += 'Seafood ';
    if (tags.isSandwich) cate += 'Sandwich ';
    if (tags.isThai) cate += 'Thai ';
    return cate;
};

const price = (level) => {
    let cost = 20;
    switch (level) {
        case 0:
            cost = 0;
            break;
        case 1:
            cost = 10;
            break;
        case 2:
            cost = 30;
            break;
        case 3:
            cost = 50;
            break;
        case 4:
            cost = 100;
            break;
        default:
            cost = 20;
            break;
    }
    return cost;
};

const details = (place_id) => {
    requests.get(`/details/json?placeid=${place_id}&key=${key}`)
        .then(({ result, status }) => {
            let weekday_text = '';
            result.opening_hours.weekday_text.map((day) => {
                weekday_text = weekday_text + ' ' + day;
            });
            let tags = {};
            result.reviews.map(review => {
                if (S(review.text).contains('sushi')) tags.isSushi = true;
                if (S(review.text).contains('korean')) tags.isKorean = true;
                if (S(review.text).contains('chinese')) tags.isChinese = true;
                if (S(review.text).contains('french')) tags.isFrench = true;
                if (S(review.text).contains('indian')) tags.isIndian = true;
                if (S(review.text).contains('italian')) tags.isItalian = true;
                if (S(review.text).contains('mexican')) tags.isMexican = true;
                if (S(review.text).contains('seafood')) tags.isSeafood = true;
                if (S(review.text).contains('sandwich')) tags.isSandwich = true;
                if (S(review.text).contains('thai')) tags.isThai = true;
            })
            console.log(`${result.name}|${category(tags)}|${price(result.price_level)}|${size}|${result.formatted_phone_number}|${result.formatted_address}|${result.rating}|${result.geometry.location.lat}|${result.geometry.location.lng}|${weekday_text}`);
            // detailsFromUrl(result.url);
        });
};

let place = 0;

const query = (pagetoken) => {
    let url = (pagetoken) ? `key=${key}&pagetoken=${pagetoken}` : `location=${location}&radius=${radius}&type=${type}&key=${key}`;
    // console.log(url);
    requests.get(`/nearbysearch/json?${url}`)
        .then(({ next_page_token, results, status }) => {
            results.map(result => {
                details(result.place_id);
                // console.log(`${place++}. ${result.place_id}`);
            })
            // console.log(`${status}`)
            if (next_page_token) {
                setTimeout(() => {
                    query(next_page_token);
                }, 3000);
            }
        });
}

query();