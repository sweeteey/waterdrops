Page({
  data:{
    detail:''
  },
  onLoad(options){
   console.log("详情接受的id",options.id)
    wx.cloud.database().collection("homelist")
      .doc(options.id)
      .get()
      .then(res=>{
        console.log("详情页成功",res)
        this.setData({
          detail:res.data
        })
     })
      .catch(res=>{
        console.log("详情页失败",res)
     })
  }
  

})