#!/usr/bin/python
import requests
response = requests.get("http://ketqua.net/")
txt = response.text
print(txt)
