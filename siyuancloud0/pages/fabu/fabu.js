let  Content=''
let pinglun=[]
Page({
  /**
   * 页面的初始数据
   */
  data: {
    default_score: 0,
    score:0,
    score_text: "",
    score_img_arr: [],
    upload_pic: [],
    is_upload: false,
    time:null,
    upload_img:[],
    text:""
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this._default_score(this.data.default_score)  },
  //获取用户输入的评论内容
  getContent(event){
    Content=event.detail.value
    console.log("获取输入的值",)
  },
  //发表评论
   fabiao(){
    if(Content.length<4){
    wx.showToast({
      icon:"none",
      title:'评论太短了',
    })
    return
  }
 }
})




