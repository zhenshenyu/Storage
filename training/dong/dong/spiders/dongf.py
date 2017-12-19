# -*- coding: utf-8 -*-
from scrapy.spiders import BaseSpider
from scrapy.http import request
from dong.items import DongItem


class DongSpider(BaseSpider):
    name = 'dongf'
    start_urls = ['http://news.people.com.cn/GB/28053']

    def parse(self, response):
        # news = response.xpath('//center/table/tbody/tr/td/table/tbody/tr/td/table/tbody/tr/text()').extract()
        news = response.xpath('//center/table/tr/td/table/tr/td/table[contains(@width, "80%")]/tr').extract()
        for new in news:
            print new
            print 'ok'
