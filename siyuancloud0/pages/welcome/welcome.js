// pages/welcome/welcome.js
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
})