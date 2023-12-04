#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];

async function getCharacter (url) {
  return new Promise((resolve, reject) => {
    request.get(url, { json: true }, (error, response, body) => {
      if (error) {
        reject(error);
        return;
      }
      resolve(body.name);
    });
  });
}

async function getCharacters (urls) {
  for (const url of urls) {
    try {
      const name = await getCharacter(url);
      console.log(name);
    } catch (error) {
      console.error(error);
    }
  }
}

request.get(`https://swapi-api.hbtn.io/api/films/${movieId}/`,
  { json: true }, async (error, response, body) => {
    if (error) {
      return console.error(error);
    }
    const urls = body.characters;
    await getCharacters(urls);
  });
