const APP = getApp()

Page({

  /**
   * 页面的初始数据
   */
  data: {
    shopInfo: {
      name: '宿舍楼栋',
      address: '校内宿舍楼'
    }
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {
    // 显示默认的楼栋信息
    this.setData({
      shopInfo: {
        name: '宿舍楼栋',
        address: '校内宿舍楼'
      }
    })
  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  // 确认楼栋选择
  confirmShop(){
    wx.setStorageSync('shopInfo', this.data.shopInfo)
    wx.setStorageSync('shopIds', 1) // 使用默认ID
    wx.switchTab({
      url: '/pages/index/index'
    })
  }
})