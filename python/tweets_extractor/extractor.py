import json
import re

def process_tweets(tweet_data, output_file, length):
    index = 0   
    tweets_list = []

    for tweet_info in tweet_data:
        print("processing tweet", index, "of", length, "...")
        index += 1
        tweet = tweet_info['tweet']
        if tweet['full_text'].startswith('RT'):
            continue
        if 'extended_entities' in tweet and 'media' in tweet['extended_entities']:
            for media in tweet['extended_entities']['media']:
                if media['type'] == 'photo' and ('caption' not in media or not media['caption']['text']):
                    continue
                else:
                    text = re.sub(r'https://t.co/[a-zA-Z0-9]+', '', tweet['full_text'])
                    text = re.sub(r'@[a-zA-Z0-9_]+', '', text)
                    tweets_list.append(text.strip())
        else:
            text = re.sub(r'https://t.co/[a-zA-Z0-9]+', '', tweet['full_text'])
            text = re.sub(r'@[a-zA-Z0-9_]+', '', text)
            tweets_list.append(text.strip())
            
    with open(output_file, 'w', encoding='utf-8') as outfile:
        for tweet in tweets_list:
            if tweet != "":
                outfile.write(tweet + '\n')

with open('tweets.js', 'r', encoding='utf-8') as file:
    data = file.read()

data = data[data.index("["):]
tweets_data = json.loads(data)

print("processing tweets ignoring retweets...")
print("number of tweets to process:", len(tweets_data))
process_tweets(tweets_data, 'tweets.txt', len(tweets_data))
print("total tweets processed:", len(tweets_data))