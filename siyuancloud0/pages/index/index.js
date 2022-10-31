Page({
  data:{
    name:'',
    id:'',
    secret:''
  },
  //获取用户名
  getname(event){
    console.log('获取输入的用户名',event.detail.value)
    this.setData({
      name:event.detail.value
    })
  },
  //获取用户账号
  getid(event){
    console.log('获取输入的用户账号',event.detail.value)
    this.setData({
      id:event.detail.value
    })
  },
  //获取用户密码
  getsecret(event){
    console.log('获取输入的用户密码',event.detail.value)
    this.setData({
      secret:event.detail.value
    })
  },
  //注册
  sign_in(){
    let name =this.data.name
    let id =this.data.id
    let secret =this.data.secret
    console.log("点击了注册")
    //用户名的校验
    if (name.length>10){
      wx.showToast({
        icon:'none',
        title:'用户名最多10位'
      })
      return
    }
    //校验账号
    if (id.length<4){
      wx.showToast({
        icon:'none',
        title:'账号至少4位'
      })
      return
    }
    //校验密码
    if(secret.length<4){
      wx.showToast({
        icon: 'none',
        title:'密码至少4位',
      })
      return
    }
    //注册功能的实现
    wx.cloud.database().collection('User').add({
      data:{
        name:name,
        id:id,
        secret:secret
      },
      success(res){
        console.log('注册成功',res)
        wx.navigateTo({
          url:'../login/login', 
        })
      },
      fail(res){
        console.log('注册失败',res)
      }

    })
  }
})