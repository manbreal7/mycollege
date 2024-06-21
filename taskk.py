import requests
from bs4 import BeautifulSoup

def scrape_business_details(url):
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        business_name = soup.find('h1').text.strip()
        address = soup.find('span', {'class': 'address'}).text.strip()
        phone = soup.find('span', {'class': 'phone'}).text.strip()
        website = soup.find('a', {'class': 'website'}).get('href').strip()

        return {
            "Business Name": business_name,
            "Address": address,
            "Phone": phone,
            "Website": website
        }
    else:
        print(f"Failed to retrieve the page. Status code: {response.status_code}")
        return None

def main():
    url_to_scrape = "https://www.example.com"
    business_details = scrape_business_details(url_to_scrape)

    if business_details:
        print("Business Details:")
        for key, value in business_details.items():
            print(f"{key}: {value}")

if __name__ == "__main__":
    main()
