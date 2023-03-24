// pages/welcome/welcome.js
/*l
Page({
  login(){
    wx.navigateTo({
      url:'../login/login', 
    })
  },
  signin(){
    wx.navigateTo({
      url:'../index/index',
    })
  }
})*/
Page({
  data: {
      userInfo: '', //用于存放获取的用户信息
  },
  async login() {            //bindtap事件
    wx.showModal({                     //手动授权弹窗
      title: '授权登录提示',
      content: '是否允许授权？',
      showCancel: true,
      confirmText: '允许',
      confirmColor: '#337AB7',
      cancelColor: '#CC463D',
      success: async res => {
        if (res.confirm) {     //用户确认
          const { userInfo: { nickName, avatarUrl } } = await
            wx.getUserProfile({    //获取用户信息，最新版本已不支持弹窗
              desc: '用户授权',
            })
 
          let { result } = await wx.cloud.callFunction({  // 调用云函数
            name: 'login',
            data: {
              nickName,
              avatarUrl
            }
          })
          this.setData({ userInfo: result })
          //getApp().globalData.userStatus = true   //用于检查用户是否登录的全局变量
          wx.navigateTo({
            url: '../chaxun/chaxun',
          })
        } else if (res.cancel) {     //用户取消
          wx.showToast({
            title: '取消授权',
            mask: true,
            icon: 'error'
          })
        }
      }
    })
  },
})