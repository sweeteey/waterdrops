// 云函数入口文件
const cloud = require('wx-server-sdk')
 
cloud.init({ env: cloud.DYNAMIC_CURRENT_ENV }) // 使用当前云环境
const db = cloud.database()
// 云函数入口函数
exports.main = async (event, context) => {
  const { OPENID } = cloud.getWXContext()
  const { nickName, avatarUrl } = event
  const user_clct = db.collection('user')
 
  const { data } = await user_clct.where({    //查询用户是否存在
    _openId: OPENID
  }).get()
 
  if (data.length === 0) {                     //如果用户不存在，添加用户
    let user = await user_clct.add({
      data: {
        nickName,
        avatarUrl,
        _openId: OPENID
      }
    })
    return {
      nickName,
      avatarUrl,
      _openId: OPENID
    }
  } else {
    return data[0]       //如果用户存在，返回该用户信息
  }
}