# Simulate a sports tournament

import csv
from math import e
import sys
import random

# Number of world cup simluations to run
N = 1000000

def main():
    # Ensure correct usage - harvard
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py filename")
    # written by yungztr
    csvFile = sys.argv[-1]
    print("World Cup Started")
    teams = []
    counts = {}
    index = 0
    teamreader = csv.reader(open(csvFile, 'r')) # Change the filename if necessary
    for zeile in teamreader:
        dictionary = {}
        team = zeile[0]
        rating = zeile[1]
        dictionary["team"] = team
        dictionary["rating"] = int(rating)
        teams.append(dictionary)
    while index < N:
        sieger = simulate_tournament(teams)
        if sieger not in counts:
            counts[sieger] = 1
        else:
            counts[sieger] += 1
        index += 1
    # -yungztr

    # Print each team's chances of winning, according to simulation - by harvard
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(
            f"{team}: {counts[team] * 100 / N:.1f}% chance of winning. The Team won {counts[team]} times")


def simulate_game(team1, team2):
    # written by harvard
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    # written by harvard
    winners = []
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):
    # written by yungztr
    if len(teams) == 1:
        return teams[0]["team"]
    nextRunde = simulate_round(teams)
    return simulate_tournament(nextRunde)
    # yungztr note - recursive method to ensure the last method call is with a single team -> the world cup winner


if __name__ == "__main__":
    main()