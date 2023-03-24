// pages/chaxun/chaxun.js
let db = wx.cloud.database()
let _ = db.command
Page({
  data: {
    datalist: [
      {
        cn: '将欲歙之，必固张之；将欲弱之，必固强之。',
        en: 'What is in the end to be shrunk must first be stretched. Whatever is to be weakened must begin by being made strong.'
      },
      {
        cn: '蒹葭苍苍，白露为霜。所谓伊人，在水一方。',
        en: 'Green, green and the greed, Dew and frost gleam. Where is she I need? Beyond the stream.'
      }
    ]
  },

  chaxun() {
    wx.navigateTo({
      url: '../zhuanyechaxun/zhuanyechaxun',
    })
  },

  jichucihui() {
    wx.navigateTo({
      url: '../jichuchaxun/jichuchaxun',
    })
  },


  /*onLoad() {
    db.collection("translation")
    .where({
      count: _.lte(2),
    })
    .get()
      .then(res => {
        console.log("获取成功", res)
        this.setData({
          datalist: res.data
        })
      })
      .catch(res => {
        console.log("获取失败", res)
      })
  }*/
})