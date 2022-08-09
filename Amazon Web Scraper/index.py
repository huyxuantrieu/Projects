from requests_html import HTMLSession
from flask import Flask, request, render_template


app = Flask(__name__)

f = open("links.txt", "r")
urlList = []
for line in f:
    urlList.append(line)
f.close()

print(urlList)

def getProductDetails(url):
    x = 0
    while (x < 30):
        try:
            htmlSession = HTMLSession()
            req = htmlSession.get(url)
            req.html.render(sleep=1)

            product = {
                'Product Name': req.html.xpath('//*[@id="productTitle"]', first=True).text,
                'Price': req.html.xpath('//*[@id="corePriceDisplay_desktop_feature_div"]/div[1]/span/span[2]/span[2]', first=True).text
                + req.html.xpath('//*[@id="corePriceDisplay_desktop_feature_div"]/div[1]/span/span[2]/span[3]', first=True).text}

            return product
        except AttributeError:
            print('retrying....', x)
            x = x+1
            if x == 30:
                print("failed!")
                exit()
        else:
            break


prices = []
for url in urlList:
    prices.append(getProductDetails(url))
length = len(prices)


@app.route('/')
def my_form():
    return render_template('frontend.html', prices=prices)


if __name__ == '__main__':
    app.run()
