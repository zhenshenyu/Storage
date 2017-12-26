# -*- coding: utf-8 -*-
from scrapy.spiders import BaseSpider
from items import DongItem



class DongSpider(BaseSpider):
    name = 'dongf'
    start_urls = ['http://news.people.com.cn/GB/28053']

    def parse(self, response):
        # news = response.xpath('//center/table/tbody/tr/td/table/tbody/tr/td/table/tbody/tr/text()').extract()
        news = response.xpath('//center/table/tr/td/table/tr/td/table[contains(@width, "80%")]/tr')
        for one_new in news:
            item = DongItem()
            ranking = one_new.xpath('td[contains(@width,"7%")]/text()')[0].extract()
            try:
                ranking = int(ranking)
            except:
                continue
            item['ranking'] = ranking
            item['link'] = one_new.xpath('td/a/@href').extract_first()
            item['title'] = one_new.xpath('td/a/text()').extract_first().encode('utf-8')
            print item['ranking'],
            print item['link'],
            print item['title']
            yield item
