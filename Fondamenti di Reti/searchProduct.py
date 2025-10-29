import sys
import urllib3
from urllib.parse import urlparse
from bs4 import BeautifulSoup
from datetime import datetime

now = datetime.now()
website_link =  sys.argv[1]
website_domain = urlparse(website_link).netloc

http = urllib3.PoolManager()

headers = { 'User-Agent' : 'Mozilla/5.0 (Windows NT 6.1; Win64; x64)' }
resp = http.request("GET", website_link, headers=headers)
soup = BeautifulSoup(resp.data, 'html.parser')

available = ''
if soup.find_all(string="Non disponibile."):
    available = "Non disponibile."
else:
    available = "Disponibilita immediata."

print(f'{now}, {website_domain}, {available}')