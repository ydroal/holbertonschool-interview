#!/usr/bin/python3
"""
count_words Module
"""
import requests


def rec_count_words(subreddit, word_list, after, result=None):
    """
    A recursive function that queries the Reddit API, parses the title of
    all hot articles, and prints a sorted count of given keywords.
    Args:
        subreddit (str): The subreddit to query from Reddit.
        word_list (List[str]): A list of keywords for which occurrences
                               in titles are to be counted.
    Returns:
        dict: A dictionary containing the word counts.
    """

    if result is None:
        result = {}

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'Countup/0.1'}
    params = {'limit': 20, 'after': after}

    res = requests.get(url, headers=headers, params=params)

    if res.status_code != 200:
        print('Error fetching data: HTTP {}'.format(res.status_code))
        return result

    res_data = res.json()
    posts = res_data['data']['children']
    for post in posts:
        title = post['data']['title'].lower().split()
        for word in word_list:
            if word in title:
                result[word] = result.get(word, 0) + 1

    after = res_data['data'].get('after')
    if after is not None:
        return rec_count_words(subreddit, word_list, after, result)
    else:
        return result


def count_words(subreddit, word_list):
    """
    Auxiliar function that call the funtion rec_count_words
    Args:
        subreddit (str): The subreddit to query from Reddit.
        word_list (List[str]): A list of keywords for which occurrences in
                               titles are to be counted.

    Returns:
        None: Not return anything.
    """
    after = ''
    keyword_list = [item.lower() for item in word_list]
    result = rec_count_words(subreddit, keyword_list, after, result=None)

    if result:
        sorted_result = sorted(result.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_result:
            if count != 0:
                print('{}: {}'.format(word, count))
