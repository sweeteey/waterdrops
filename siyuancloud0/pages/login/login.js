Page({
  data:{
    id:'',
    secret:''
  },
  //获取输入的账号
  getid(event){
    console.log('账号',event.detail.value),
   this.setData({
    id:event.detail.value
  })
  },
  //获取输入的密码
  getsecret(event){
    console.log('密码',event.detail.value)
     this.setData({
      secret:event.detail.value
    })
  },

  login(){
    let id = this.data.id
    let secret = this.data.secret
    console.log('账号',id,'密码',secret)
    //校验
    if(id.length < 4) {
    wx.showToast({
      icon:'none',
      title: '账号至少4位',
    })
    return
  }
    if(secret.length < 4) {
    wx.showToast({
      icon:'none',
      title: '密码至少4位',
    })
    return
  }
  //登录
   wx.cloud.database().collection('User').where({
    id:id
   }).get({
    success(res){
      console.log("获取数据成功",res)
      let user = res.data[0]
      console.log("user",user)
      if(secret=user.secret){
        console.log('登录成功')
        wx.navigateTo({
          url:'../home/home',
        })
      }else{
        console.log('登录失败')
      }
    },
    fail(res){
      console.log("获取数据失败",res)
    }
  })
  }
})