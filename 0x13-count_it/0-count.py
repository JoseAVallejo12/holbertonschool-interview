#!/usr/bin/python3
"""Get request to reddit API"""
import requests
import re


def count_words(subreddit, word_list, first_call=True, after="", dic={}):
    """Cound # of keywords"""
    if first_call:
        word_list = list(set(word_list))
        d = count_words(subreddit, word_list, False)
        if d:
            for key, value in sorted(d.items(), key=lambda x: (-x[1], x[0])):
                print("{}: {}".format(key, value))
        elif d is None:
            return None
    else:
        base_url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        h = {'User-Agent': 'Reddit API test'}
        params = {'limit': 200, 'after': after}
        r = requests.get(base_url, headers=h,
                         allow_redirects=False, params=params)
        if r.status_code != 200:
            return None
        d = r.json()
        if after is None:
            return dic
        children = d.get('data', {}).get('children')
        for child in children:
            title = child.get('data', {}).get('title').lower()
            for word in word_list:
                regex_exp = re.compile(word + '[\s,.]')
                if re.search(regex_exp, title):
                    if word not in dic:
                        dic[word] = 1
                    else:
                        dic[word] += 1
        p = d.get('data', {}).get('after')
        return count_words(subreddit, word_list, False, p, dic)
