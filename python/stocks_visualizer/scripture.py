import http.client
import json
import streamlit as st
from streamlit_echarts import st_echarts

reader = open("api.json", "r", encoding="utf-8")
key_collection = json.load(reader)
bearer = key_collection["alphavantage"]["key"]

def speichern(objek, datei):
    with open(datei, 'w') as json_file:
        json.dump(objek, json_file, indent=2)

aktien = [
    "AAPL",
    "AMD",
    # "IBM",
]


# WICHTIG
# DIe api hat nur 25 calls pro tag
# falls nicht geht, versuchen data.json backup zu holen
# und dann unten lokal laden

# data = {"aktie": {}}

# for aktie in aktien:
#     conn = http.client.HTTPSConnection("www.alphavantage.co")
#     headersList = {
#         "Accept": "*/*",
#         "User-Agent": "VS Code"
#     }
#     payload = ""
#     conn.request("GET", f"/query?function=TIME_SERIES_WEEKLY&symbol={aktie}&apikey={bearer}", payload, headersList)
#     response = conn.getresponse()
#     result = response.read()
#     data["aktie"][aktie] = json.loads(result)
#     data['aktie'][aktie]['Weekly Time Series'] = dict(list(data['aktie'][aktie]['Weekly Time Series'].items())[:5]) # ChatGPT Zeile

# speichern(data, "data.json")
# print("Daten gespeichert!")

lokal = open("data.json", 'r')
data = json.load(lokal)

alle_aktien = []

for aktie, details in data["aktie"].items():
    zeitachse = list(details["Weekly Time Series"].keys())
    close_wert = [float(details["Weekly Time Series"][datum]["4. close"]) for datum in zeitachse]
    series_data = {"name": aktie, "type": "line", "data": close_wert}
    alle_aktien.append(series_data)

options = {
    "xAxis": {
        "type": "category",
        "data": zeitachse,
    },
    "yAxis": {"type": "value"},
    "series": alle_aktien,
}

st_echarts(options=options)