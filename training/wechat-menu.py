# _*_ coding: utf-8 _*_
from wechat_sdk import WechatConf,WechatBasic

conf = WechatConf(
    token='kaigong123',
    appid='wx0ed326c5c32d3100',
    appsecret='334b82cafb04e83f1faffd93ff92849a',
    encrypt_mode='normal',  # 可选项：normal/compatible/safe，分别对应于 明文/兼容/安全 模式
    encoding_aes_key='4HTwrtNQSecrnfbjHQlkEvl2NX9Bm3DTF8AKG1SCmP7'  # 如果传入此值则必须保证同时传入 token, appid
)
wechat = WechatBasic(conf=conf)

menu = {
    'button':[
        {
            'type': 'click',
            'name': '今日歌曲',
            'key': 'V1001_TODAY_MUSIC'
        },
        {
            'type': 'click',
            'name': '歌手简介',
            'key': 'V1001_TODAY_SINGER'
        },
        {
            'name': '菜单',
            'sub_button': [
                {
                    'type': 'view',
                    'name': '搜索',
                    'url': 'http://www.soso.com/'
                },
                {
                    'type': 'view',
                    'name': '视频',
                    'url': 'http://v.qq.com/'
                },
                {
                    'type': 'click',
                    'name': '赞一下我们',
                    'key': 'V1001_GOOD'
                }
            ]
        }
    ]
}
resl = wechat.create_menu(menu_data=menu)
print wechat.get_menu()