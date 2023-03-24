// pages/jichuchaxun/jichuchaxun.js
const the_md5 = require("../../utils/md5")
var inputTxt = '';
var selectText='';

Page ({
  /**   * 页面的初始数据   */  
  data: {
    txt: "",
    translateResult: "",
    selectArray: [
      {
        "id": "10",
        "text": "中译英"
      },
      {
        "id": "21",
        "text": "英译中" 
      }
    ]
  },
  //清空  
  clearBut: function (e) {
    this.setData({
      txt: '',
      translateResult: ''
    })
  },
  //翻译
  translateBut: function () {
    var appid = '20230324001612686';
    var key = 'T7MVqXQk0iEXLiQ2rK31';
    var salt = (new Date).getTime();
    var from = 'auto';
    var to = 'auto';
    if(selectText==="中译英") {
      from = 'zh',
      to = 'en'
    }
    else if(selectText==="英译中") {
      from = 'en',
      to = 'zh'
    }
    var query = inputTxt;
    var str1 = appid + query + salt + key;
    var sign = the_md5.MD5(str1);
    let that = this;   
    if (query === undefined || query === '') {
      return;
    }
    wx.request({
      url: 'https://api.fanyi.baidu.com/api/trans/vip/translate',
      type: 'get',
      data: {
        q: query,
        appid: appid,
        salt: salt,
        from: from,
        to: to,
        sign: sign
      },
      success: function (res) {
        console.log(res)
        that.setData({
          translateResult: res.data.trans_result[0].dst
        })
        console.log(translateResult)
      },
    })
  },
  //获取要翻译的内容
  getInputValue: function (e) {
    inputTxt = e.detail.value
  },
  //获取翻译类型
  select: function(e){
    selectText = e.detail.text;
  },
})
