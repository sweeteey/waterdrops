// pages/chaxun/chaxun.js
let db = wx.cloud.database()
let _ = db.command
let key = ""
Page({
  data: {
    /*key: null,*/
    datalist: []
  },
  getKey(e) {
    /*this.setData({
      key: e.detail.value
    }),*/
    key = e.detail.value
  },
  sousuo() {
    console.log(key)
    /*if(this.data.key) {*/
    if(key){
      console.log('可以执行搜索')
      /*let key = this.data.key*/
      db.collection('translation')
      .where({
        //使用正则查询,实现模糊查询
        cn: db.RegExp({
          regexp: key,
          //options: 'i',
        }),
      })
      .get()
      .then(res => {
        console.log('查询成功: ', res)
        this.setData({
          datalist: res.data
        })
      })
      .catch(res => {
        console.log('查询失败: ', res)
      })
    }
    else {
      wx.showToast({
        icon: 'error',
        title: '请输入内容',
      })
    }
  },

  onLoad() {
    console.log('专业查询页面')
  }
})